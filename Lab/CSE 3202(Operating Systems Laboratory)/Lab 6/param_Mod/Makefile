obj-m += Hello.o

KDIR = /lib/modules/linux-headers-$(uname -r)

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
