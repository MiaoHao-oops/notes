LICENSE = "CLOSED"

inherit module

SRC_URI = "file://Makefile \
           file://lab2-io-port.c \
          "

S = "${WORKDIR}"

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.

# RPROVIDES:${PN} += "kernel-module-lab2-io-port"
