

def CreateObject(ObjName,whereIs):
    startingPos = int(input("Starting Pos: "))
    width = input("Width of Sprite: ")
    height = input("Height of Sprite: ")
    frameRate = input("Amount of frames for Sprite: ")
    refreshRate = input("Refresh rate for Sprite: ")
    objString = whereIs + " " + ObjName + " " + width + " " + height + " "+str(startingPos)+" " + frameRate + " " + refreshRate + "\n"
    states = int(input("Availibe states: "))
    stateStartingPos = int(startingPos)
    for i in range(0, states):
        print("Creating %d state" % (i))
        statename = input("Name of state: ")
        stateFrameRate = input("Amount of frames for State: ")
        stateRefreshRate = input("Refresh rate for State: ")
        stateStartingPos+= int(height)
        objString += statename + " "+str(stateStartingPos)+" " + stateFrameRate + " " + stateRefreshRate + "\n"          
    
    return objString 
