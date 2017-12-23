#!/usr/bin/env python

import rospy
import time
from geometry_msgs.msg import Twist
from barc.msg import ECU


# update
def callback_function(data):
    newECU.motor = newECU.motor + round(data.linear.x*0.01,5)       # input acceleration
    newECU.servo = newECU.servo + round(data.angular.z*0.01,5)      # input steering angle
    pubname.publish(newECU)

# state estimation node
def TwistToECU():

    # initialize node
    rospy.init_node('TwistToECU', anonymous=True)
    
    global pubname , newECU
    newECU = ECU() 
    # topic subscriptions / publications
    pubname = rospy.Publisher('ecu',ECU, queue_size = 100)

    rospy.Subscriber('turtle1/cmd_vel', Twist, callback_function)
    # set node rate
    loop_rate   = 50
    ts          = 1.0 / loop_rate
    rate        = rospy.Rate(loop_rate)
    t0          = time.time()

    rospy.spin()

if __name__ == '__main__':
    try:
       TwistToECU()
    except rospy.ROSInterruptException:
        pass
