import cv2  # for image processing
import mediapipe as mp  # for hand tracking
import pyautogui  # for controlling the mouse


class VirtualMouse:
    def __init__(self):
        # getting necessary objects and variables
        self.cap = cv2.VideoCapture(0)
        self.hand_detector = mp.solutions.hands.Hands()  # type: ignore
        self.screen_width, self.screen_height = pyautogui.size()

        # coordinates of the landmarks
        self.wrist_y = 0
        self.wrist_x = 0
        self.thumb_y = 0
        self.thumb_x = 0
        self.index_y = 0
        self.index_x = 0

        self.mode = 0
        '''
        0: no action
        1: left click
        2: move cursor
        3: right click
        '''
        self.mode_colors = ((0, 0, 255), (255, 0, 0), (0, 255, 0),
                            (0, 255, 255))
        '''
        0: red
        1: blue
        2: green
        3: yellow
        '''

    def __del__(self):
        self.cap.release()
        cv2.destroyAllWindows()

    def relative_distance(self):
        '''
        returns the ratio
        (distance between the wrist and the middle of the finger tips) / (distance between the finger tips)
        '''
        mid_x = (self.index_x + self.thumb_x)/2
        mid_y = (self.index_y + self.thumb_y)/2

        wrist_distance = ((mid_y - self.wrist_y)**2 +
                          (mid_x - self.wrist_x)**2)**0.5

        finger_distance = ((self.index_y - self.thumb_y) **
                           2 + (self.index_x - self.thumb_x)**2)**0.5

        return wrist_distance / finger_distance

    def handle_detection(self):
        '''
        left click (4, ...]
        dead zone  (3.5, 4]
        move cursor(2, 3.5]
        dead zone  (1.8, 2]
        right click (..., 1.8]
        '''
        if self.relative_distance() > 4:
            self.mode = 1
            print('\rleft click :', self.relative_distance(), ' '*20, end='')
            pyautogui.click()
            pyautogui.sleep(1)

        elif self.relative_distance() > 3.5:
            self.mode = 0
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')

        elif self.relative_distance() > 2:
            self.mode = 2
            print('\rmove cursor:', self.relative_distance(), ' '*20, end='')
            pyautogui.moveTo((self.index_x + self.thumb_x)/2,
                             (self.index_y + self.thumb_y)/2)

        elif self.relative_distance() > 1.8:
            self.mode = 0
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')

        else:
            self.mode = 3
            print('\rright click:', self.relative_distance(), ' '*20, end='')
            pyautogui.click(button='right')
            pyautogui.sleep(1)

    def run(self):
        while True:
            _, frame = self.cap.read()
            frame = cv2.flip(frame, 1)
            frame_height, frame_width, _ = frame.shape
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            hands = self.hand_detector.process(rgb_frame).multi_hand_landmarks

            if hands:
                # get the first hand detected to avoid focus on the wrong hand
                landmarks = hands[hands.__len__()-1].landmark

                # wrist
                landmark = landmarks[0]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self.mode_colors[self.mode])

                self.wrist_x = self.screen_width/frame_width*x
                self.wrist_y = self.screen_height/frame_height*y

                # thumb
                landmark = landmarks[4]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self.mode_colors[self.mode])

                self.thumb_x = self.screen_width/frame_width*x
                self.thumb_y = self.screen_height/frame_height*y

                # index
                landmark = landmarks[8]
                x = int(landmark.x*frame_width)
                y = int(landmark.y*frame_height)

                cv2.circle(img=frame, center=(x, y), radius=10,
                           color=self.mode_colors[self.mode])

                self.index_x = self.screen_width/frame_width*x
                self.index_y = self.screen_height/frame_height*y

                self.handle_detection()

            cv2.imshow('Virtual Mouse', frame)
            cv2.waitKey(1)


if __name__ == '__main__':  # if the file is run directly
    vm = VirtualMouse()
    vm.run()
