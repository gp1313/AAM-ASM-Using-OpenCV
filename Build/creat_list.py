import sys
import os

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "usage: create_list <image_path>"
        sys.exit(1)
    BASE_PATH=sys.argv[1]
    for filename in os.listdir(BASE_PATH):
        abs_path = "%s/%s" % (BASE_PATH, filename)
        if filename.find(".png") != -1:
            print "%s" % (abs_path)

