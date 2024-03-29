from __future__ import print_function
import sys
import cv2
import argparse


def main(argv):

    quit_check = False

    #capture from camera at location 0
    cap = cv2.VideoCapture(0)

    # Change the camera setting using the set() function
    # cap.set(cv2.CAP_PROP_EXPOSURE, -6.0)
    # cap.set(cv2.CAP_PROP_GAIN, 4.0)
    # cap.set(cv2.CAP_PROP_BRIGHTNESS, 144.0)
    # cap.set(cv2.CAP_PROP_CONTRAST, 27.0)
    # cap.set(cv2.CAP_PROP_HUE, 13.0) # 13.0
    # cap.set(cv2.CAP_PROP_SATURATION, 28.0)
    # Read the current setting from the camera
    test = cap.get(cv2.CAP_PROP_POS_MSEC)
    ratio = cap.get(cv2.CAP_PROP_POS_AVI_RATIO)
    frame_rate = cap.get(cv2.CAP_PROP_FPS)
    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    brightness = cap.get(cv2.CAP_PROP_BRIGHTNESS)
    contrast = cap.get(cv2.CAP_PROP_CONTRAST)
    saturation = cap.get(cv2.CAP_PROP_SATURATION)
    hue = cap.get(cv2.CAP_PROP_HUE)
    gain = cap.get(cv2.CAP_PROP_GAIN)
    exposure = cap.get(cv2.CAP_PROP_EXPOSURE)
    print("Test: ", test)
    print("Ratio: ", ratio)
    print("Frame Rate: ", frame_rate)
    print("Height: ", height)
    print("Width: ", width)
    print("Brightness: ", brightness)
    print("Contrast: ", contrast)
    print("Saturation: ", saturation)
    print("Hue: ", hue)
    print("Gain: ", gain)
    print("Exposure: ", exposure)

    while quit_check == False:
        ret, img = cap.read()
        cv2.imshow("input", img)

        key = cv2.waitKey(10)
        if key == 27: # press escape to exit
            break

        # send data to matlab

    cv2.destroyAllWindows()
    cv2.VideoCapture(0).release()

    # PySerial functionality
    position(pos)

if __name__ == '__main__':
    main(sys.argv)

def position(pos):
    