obj-m := device_setup.o
obj-m += driver_test.o
driver_test-objs := platform_driver.o

all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

