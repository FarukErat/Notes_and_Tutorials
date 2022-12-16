import cv2  # for image processing
import mediapipe as mp  # for hand tracking
import pyautogui  # for controlling the mouse


class VirtualMouse:  # for creating the virtual mouse class
    def __init__(self):  # for initializing the class
        self.cap = cv2.VideoCapture(0)  # for capturing the video
        self.hand_detector = mp.solutions.hands.Hands()  # for detecting the hand
        self.drawing_utils = mp.solutions.drawing_utils  # for drawing the hand

        self.screen_width, self.screen_height = pyautogui.size()
        self.wrist_y = 0  # for storing the y coordinate of the wrist
        self.wrist_x = 0  # for storing the x coordinate of the wrist
        self.index_y = 0  # for storing the y coordinate of the index finger
        self.thumb_y = 0  # for storing the y coordinate of the thumb
        self.index_x = 0  # for storing the x coordinate of the index finger
        self.thumb_x = 0  # for storing the x coordinate of the thumb

    def __del__(self):  # for deleting the object
        self.cap.release()  # for releasing the video capture
        cv2.destroyAllWindows()  # for destroying all the windows

    def relative_distance(self):
        mid_x = (self.index_x + self.thumb_x)/2
        mid_y = (self.index_y + self.thumb_y)/2
        wrist_distance = ((mid_y - self.wrist_y)**2 + (mid_x - self.wrist_x)**2)**0.5
        finger_distance = ((self.index_y - self.thumb_y)**2 + (self.index_x - self.thumb_x)**2)**0.5
        return wrist_distance / finger_distance

    def handle_detection(self):
        # if the distance between the thumb and the index finger is less than 20
        if self.relative_distance() > 4:
            print('\rleft click:', self.relative_distance(), '      ', end='')
            pyautogui.click()  # for clicking the mouse
            pyautogui.sleep(1)  # for waiting for 1 second
        # if the distance between the thumb and the index finger is less than 100
        elif self.relative_distance() > 2:
            print('\rdead zone:', self.relative_distance(), '      ', end='')
            pass  # dead zone
        elif self.relative_distance() > 1.5:
            print('\rmove cursor:', self.relative_distance(), '      ', end='')
            # for moving the mouse
            pyautogui.moveTo((self.index_x + self.thumb_x)/2,
                             (self.index_y + self.thumb_y)/2)
        else:
            print('\rright click:', self.relative_distance(), '      ', end='')
            pyautogui.click(button='right')  # right click
            pyautogui.sleep(1)  # for waiting for 1 second

    def run(self):  # for running the virtual mouse
        while True:  # for capturing the video frame by frame
            _, frame = self.cap.read()  # for reading the video frame
            frame = cv2.flip(frame, 1)  # for flipping the frame
            frame_height, frame_width, _ = frame.shape  # for getting the frame size
            # for converting the frame to RGB
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            output = self.hand_detector.process(
                rgb_frame)  # for detecting the hand
            hands = output.multi_hand_landmarks  # for getting the hand landmarks

            if hands:  # if hand is detected
                for hand in hands:  # for each hand
                    landmarks = hand.landmark  # for getting the hand landmarks
                    for id, landmark in enumerate(landmarks):  # for each landmark
                        # for getting the x coordinate
                        x = int(landmark.x*frame_width)
                        # for getting the y coordinate
                        y = int(landmark.y*frame_height)

                        if id == 8:  # if the landmark is the index finger
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))  # for drawing the circle
                            # for getting the x coordinate of the index finger
                            self.index_x = self.screen_width/frame_width*x
                            # for getting the y coordinate of the index finger
                            self.index_y = self.screen_height/frame_height*y
                            self.handle_detection()

                        if id == 4:  # if the landmark is the thumb
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))  # for drawing the circle
                            # for getting the x coordinate of the thumb
                            self.thumb_x = self.screen_width/frame_width*x
                            # for getting the y coordinate of the thumb
                            self.thumb_y = self.screen_height/frame_height*y
                            self.handle_detection()

                        if id == 0:  # if the landmark is the wrist
                            cv2.circle(img=frame, center=(x, y), radius=10,
                                       color=(0, 255, 255))  # for drawing the circle
                            # for getting the x coordinate of the wrist
                            self.wrist_x = self.screen_width/frame_width*x
                            # for getting the y coordinate of the wrist
                            self.wrist_y = self.screen_height/frame_height*y

            cv2.imshow('Virtual Mouse', frame)  # for displaying the frame
            cv2.waitKey(1)  # for waiting for 1 millisecond


if __name__ == '__main__':  # if the file is run directly
    vm = VirtualMouse()  # for creating the virtual mouse object
    vm.run()  # for running the virtual mouse
