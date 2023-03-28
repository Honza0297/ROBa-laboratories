

class Twist:
    def __init__(self):
        self.linear  = Linear()
        self.angular = Angular()


class Linear:
    def __init__(self, x = 0.0, y = 0.0, z = 0.0):
        self.x = x
        self.y = y
        self.z = z
        

class Angular:
    def __init__(self, x = 0.0, y = 0.0, z = 0.0):
        self.x = x
        self.y = y
        self.z = z
        

T = Twist()

pub.publish
print(T.angular.x)



