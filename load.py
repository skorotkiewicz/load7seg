#!/usr/bin/python
from smbus import SMBus
import os

bus = SMBus(1)
slaveAddress = 0x08
data_to_send_to_Arduino = str(os.getloadavg()[0])

def StringToBytes(val):
    retVal = []
    for c in val:
        retVal.append(ord(c))
    return retVal

bus.write_i2c_block_data(slaveAddress, 0x00,StringToBytes(data_to_send_to_Arduino))