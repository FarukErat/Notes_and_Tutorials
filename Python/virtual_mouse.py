import cv2  # for image processing
import mediapipe as mp  # for hand tracking
import pyautogui  # for controlling the mouse


class VirtualMouse:
    def __init__(self):
        # getting necessary objects and variables
        self.cap = cv2.VideoCapture(0)
        self.hand_detector = mp.solutions.hands.Hands()
        self.drawing_utils = mp.solutions.drawing_utils
        self.screen_width, self.screen_height = pyautogui.size()

        # coordinates of the landmarks
        self.wrist_y = 0
        self.wrist_x = 0
        self.index_y = 0
        self.thumb_y = 0
        self.index_x = 0
        self.thumb_x = 0

    def __del__(self):
        self.cap.release()
        cv2.destroyAllWindows()

    def relative_distance(self):
        mid_x = (self.index_x + self.thumb_x)/2
        mid_y = (self.index_y + self.thumb_y)/2

        wrist_distance = ((mid_y - self.wrist_y)**2 +
                          (mid_x - self.wrist_x)**2)**0.5

        finger_distance = ((self.index_y - self.thumb_y) **
                           2 + (self.index_x - self.thumb_x)**2)**0.5

        return wrist_distance / finger_distance

    def handle_detection(self):
        if self.relative_distance() > 4:
            print('\rleft click :', self.relative_distance(), ' '*20, end='')
            pyautogui.click()
            pyautogui.sleep(1)

        elif self.relative_distance() > 3:
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')
            pass

        elif self.relative_distance() > 2:
            print('\rmove cursor:', self.relative_distance(), ' '*20, end='')
            pyautogui.moveTo((self.index_x + self.thumb_x)/2,
                             (self.index_y + self.thumb_y)/2)

        elif self.relative_distance() > 1.5:
            print('\rdead zone  :', self.relative_distance(), ' '*20, end='')
            pass

        else:
            print('\rright click:', self.relative_distance(), ' '*20, end='')
            pyautogui.click(button='right')
            pyautogui.sleep(1)

    def run(self):
        while True:
            _, frame = self.cap.read()
            frame = cv2.flip(frame, 1)
            frame_height, frame_width, _ = frame.shape
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            output = self.hand_detector.process(rgb_frame)
            hands = output.multi_hand_landmarks

            if hands:
                for hand in hands:
                    landmarks = hand.landmark
                    for id, landmark in enumerate(landmarks):
                        x = int(landmark.x*frame_width)
                        y = int(landmark.y*frame_height)

                        if id == 0:  # if the landmark is the wrist
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))
                            self.wrist_x = self.screen_width/frame_width*x
                            self.wrist_y = self.screen_height/frame_height*y

                        if id == 4:  # if the landmark is the thumb
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))
                            self.thumb_x = self.screen_width/frame_width*x
                            self.thumb_y = self.screen_height/frame_height*y

                        if id == 8:  # if the landmark is the index finger
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))
                            self.index_x = self.screen_width/frame_width*x
                            self.index_y = self.screen_height/frame_height*y
                            self.handle_detection()

            cv2.imshow('Virtual Mouse', frame)
            cv2.waitKey(1)


if __name__ == '__main__':  # if the file is run directly
    vm = VirtualMouse()
    vm.run()
