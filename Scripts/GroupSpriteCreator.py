from CreateObjects import CreateObject


def CreateSpriteGroup():
    location = input("Location of Texture for Sprite: ")
    SpriteGroup = ""
    true = 1
    while true == 1:
        repeat = input ("Would You use this same Texture location?[y/n]")
        if repeat.lower() in['n', 'no']:
                location = input("Location of Texture for Sprite: ")
        objName = input("Sprite Name:")
        SpriteGroup += CreateObject(objName, location)
        choice = input("Would You like to add another sprite?[y/n]")
        if choice.lower() in ['n', 'no']:
            return SpriteGroup
    
