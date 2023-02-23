import pyautogui
import time

msg = "Hello World"
repeat = 20

time.sleep(5)
for i in range(repeat):
    pyautogui.typewrite(msg)
    pyautogui.press("enter")
