TARGET := dev_mod
obj-m += $(TARGET).o

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

load:
	insmod ./$(TARGET).ko

unload:
	rmmod ./$(TARGET).ko
