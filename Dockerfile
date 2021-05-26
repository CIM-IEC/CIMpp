FROM fedora:27

LABEL \
	org.label-schema.schema-version = "2.1.0" \
	org.label-schema.name = "libcimpp" \
	org.label-schema.license = "MPL" \
	org.label-schema.vendor = "Institute for Automation of Complex Power Systems, RWTH Aachen University" \
	org.label-schema.author.name = "Lukas Razik" \
	org.label-schema.author.email = "lrazik@eonerc.rwth-aachen.org" \
	org.label-schema.vcs-url = "https://github.com/rwth-acs/libcimpp"

RUN dnf -y update

# Toolchain
RUN dnf -y install \
	git \
	gcc-c++ \
	make \
	doxygen graphviz \
	xerces-c-devel \
	python3-pip rpmdevtools


RUN pip3 install xmltodict chevron cmake
# Some of the dependencies are only available in our own repo
ADD https://packages.fein-aachen.org/redhat/fein.repo /etc/yum.repos.d/


