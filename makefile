
############################################################
# All targets
############################################################

TARGETS := bit_manip

############################################################
# Common build rules
############################################################
OBJDIR := ./obj
OUTPUTDIR := ./output
SOURCEDIR := ./source

#COMPILEFLAGS := -g -Wall -DMULTI_PASS_TESTS
COMPILEFLAGS := -g -Wall $(MULTI_FLAG)
#COMPILEFLAGS += -ffunction-sections
#LINKERFLAGS := -Wl,-Map=$(OUTPUTDIR)/out.map
#LINKERFLAGS += -Wl,--print-map>$(OUTPUTDIR)/outmap.txt
#LINKERFLAGS += -Wl,--cref
#LINKERFLAGS += -Wl,--gc-sections


$(TARGETS): | $(OUTPUTDIR)

$(OUTPUTDIR):
	mkdir $(OUTPUTDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OUTPUTDIR)
	rm -rf $(OBJDIR)

############################################################

BIT_MANIP_DIR := ./source

BIT_MANIP_OBJECTS := $(addprefix $(OBJDIR)/, \
             bit_manip.o \
             bit_manip_print_funcs.o \
             bit_manip_algorithms.o \
             bit_manip_interface.o \
	     )

BIT_MANIP_HEADERS := $(BIT_MANIP_DIR)/bit_manip.h

############################################################

bit_manip: $(BIT_MANIP_OBJECTS)
	gcc $(LINKERFLAGS) $(BIT_MANIP_OBJECTS) -o $(OUTPUTDIR)/$@

$(OBJDIR)/%.o : $(BIT_MANIP_DIR)/%.c $(BIT_MANIP_HEADERS) $(COMMON_HEADERS)
	gcc $(COMPILEFLAGS) -c $< -o $@

$(BIT_MANIP_OBJECTS): | $(OBJDIR)
