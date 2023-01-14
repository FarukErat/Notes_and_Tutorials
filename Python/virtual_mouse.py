import cv2  # for image processing
import mediapipe as mp  # for hand tracking
import pyautogui  # for controlling the mouse


class VirtualMouse:
    # coordinates of the landmarks
    _wrist_y = 0
    _wrist_x = 0
    _thumb_y = 0
    _thumb_x = 0
    _index_y = 0
    _index_x = 0

    _clicked = False

    _mode = 0
    '''
    0: no action
    1: left click
    2: move cursor
    3: right click
    '''
    _mode_colors = ((0, 0, 255), (255, 0, 0), (0, 255, 0),
                    (0, 255, 255))
    '''
    0: red
    1: blue
    2: green
    3: yellow
    '''

    def __init__(self):
        # getting necessary objects and variables
        self.cap = cv2.VideoCapture(0)
        self.hand_detector = mp.solutions.hands.Hands()  # type: ignore
        self.screen_width, self.screen_height = pyautogui.size()

        # pyautogui.FAILSAFE = False
        pyautogui.PAUSE = 0

    def __del__(self):
        self.cap.release()
        cv2.destroyAllWindows()

    def relative_distance(self):
        '''
        returns the ratio
        (distance between the wrist and the middle of the finger tips) / (distance between the finger tips)
        '''
        mid_x = (self._index_x + self._thumb_x)/2
        mid_y = (self._index_y + self._thumb_y)/2

        wrist_distance = ((mid_y - self._wrist_y)**2 +
                          (mid_x - self._wrist_x)**2)**0.5

        finger_distance = ((self._index_y - self._thumb_y) **
                           2 + (self._index_x - self._thumb_x)**2)**0.5

        return wrist_distance / finger_distance

    def closest_hand(self, hands):
        if len(hands) == 0:
            return None

        def distance(landmark):
            return ((landmark[0].x - landmark[5].x)**2 +
                    (landmark[0].y - landmark[5].y)**2)**0.5

        largest_hand = hands[0]
        largest_distance = distance(largest_hand.landmark)

        for hand in hands:
            if distance(hand.landmark) > largest_distance:
                largest_hand = hand
                largest_distance = distance(hand.landmark)

        return largest_hand

    def handle_detection(self):
        '''
        left click (4, ...]
        dead zone  (3.5, 4]
        move cursor(2, 3.5]
        dead zone  (1.8, 2]
        right click (..., 1.8]
        '''
        rel_dist = self.relative_distance()

        if rel_dist > 7:
            self._mode = 0
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')
            self._clicked = False

        elif rel_dist > 4:
            self._mode = 1
            print('\rleft click :', self.relative_distance(), ' '*20, end='')
            if not self._clicked:
                pyautogui.click()
                self._clicked = True

        elif rel_dist > 3.5:
            self._mode = 0
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')
            self._clicked = False

        elif rel_dist > 2:
            self._mode = 2
            print('\rmove cursor:', self.relative_distance(), ' '*20, end='')
            pyautogui.moveTo((self._index_x + self._thumb_x)/2,
                             (self._index_y + self._thumb_y)/2,
                             duration=0.15)
            self._clicked = False

        elif rel_dist > 1.8:
            self._mode = 0
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')
            self._clicked = False

        else:
            self._mode = 3
            print('\rright click:', self.relative_distance(), ' '*20, end='')
            if not self._clicked:
                pyautogui.click(button='right')
                self._clicked = True

    def run(self):
        while True:
            _, frame = self.cap.read()
            frame = cv2.flip(frame, 1)
            frame_height, frame_width, _ = frame.shape
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            hands = self.hand_detector.process(rgb_frame).multi_hand_landmarks

            if hands:
                # get the first hand detected to avoid focus on the wrong hand
                landmarks = self.closest_hand(hands).landmark  # type: ignore

                # wrist
                landmark = landmarks[0]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self._mode_colors[self._mode])

                self._wrist_x = self.screen_width/frame_width*x
                self._wrist_y = self.screen_height/frame_height*y

                # thumb
                landmark = landmarks[4]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self._mode_colors[self._mode])

                self._thumb_x = self.screen_width/frame_width*x
                self._thumb_y = self.screen_height/frame_height*y

                # index
                landmark = landmarks[8]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self._mode_colors[self._mode])

                self._index_x = self.screen_width/frame_width*x
                self._index_y = self.screen_height/frame_height*y

                self.handle_detection()

            cv2.imshow('Virtual Mouse', frame)
            cv2.waitKey(1)


if __name__ == '__main__':  # if the file is run directly
    vm = VirtualMouse()
    vm.run()
