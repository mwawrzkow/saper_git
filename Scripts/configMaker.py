import os
from GroupSpriteCreator import CreateSpriteGroup


def ConfigFileCreation():
    strhei = "W_height"
    strwid = "W_width"
    window_height = input("Height Of Window:")
    window_width = input("Width of Window:")
    print("Creating File Dependences...")
    output = strhei + " = " + window_height +"\n"
    output+= strwid + " = " + window_width + "\n"
    while 1:
        name = input("Name of dependence:")
        value = input("Value of dependence:")
        createdir = input("Create Dir?[y/n]")
        if createdir.lower() in ['y','ye','yes']:
            print("Checking if dir Exist.")
            if not os.path.exists(value):
                print("Dir Does not Exist.\nCreating Dir.")
                os.makedirs(value)
        createfile = input("Create config.conf file?")
        if createfile.lower() in ['y','ye','yes']:
            file = open(value+"/config.conf", 'w')
            file.write(CreateSpriteGroup())
            file.close()
        output+= name + " = " + value + "\n"
        breakloop = input("Stop Writing Dependences?[y/n]")
        if breakloop.lower() in ['y','ye','yes']:
            break
    file = open("config.conf", 'w')
    file.write(output)


 