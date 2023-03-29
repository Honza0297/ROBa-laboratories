

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
        

# class Twist:
#     def __init__(self):
#         self.linear  = Linear()
#         self.angular = Angular()


# class Linear:
#     x:float
#     y:float
#     z:float
    

# class Angular:
#     x:float
#     y:float
#     z:float
        

message = Twist()
message.linear.x  = 5
message.angular.z = 5

# pub.publish(message)


print(message.angular.x)


class Sonar_data:
    def __init__(self, front=0, front_left=0, front_right=0, 
                       back=0, back_left=0, back_right=0,):
        self.front       = front
        self.front_left  = front_left
        self.front_right = front_right
        self.back        = back
        self.back_left   = back_left
        self.back_right  = back_right



data = Sonar_data()
print(data.front)

message = Sonar_data()
message.front  = 5
message.back_left = 5

pub.publish(message)



