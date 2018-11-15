
# To build modules run "make"
build=INTEL

ifeq ($(build),INTEL)

    # declare the modules to be called
    obj-m := hello.o 

    # Assume the source tree is where the running kernel was built
    KERNELDIR = /lib/modules/$(shell uname -r)/build

    # The current directory is passed to sub-makes as argument
    PWD := $(shell pwd)

intel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	echo "bulding module for intel architecture:" 

    
else

    obj-m := hello.o 

    CROSS_COMPILE=arm-linux- 
    ARCH=arm 
    KERNELDIR=/usr/src/kernels/linux-2.6.32.2
    PWD       := $(shell pwd)

arm_modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) LDDINC=$(PWD)/../include modules
	echo "bulding module for arm architecture:"

    
endif



clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: clean


