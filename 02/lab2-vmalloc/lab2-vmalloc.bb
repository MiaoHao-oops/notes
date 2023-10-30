LICENSE = "CLOSED"

SRC_URI = "file://lab2-vmalloc.c \
           file://Makefile \
         "

inherit module 

S = "${WORKDIR}"

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.

# RPROVIDES:${PN} += "kernel-module-lab2-vmalloc"
