N64KITDIR = C:\nintendo\n64kit

NVFDIR = $(N64KITDIR)\niff\nvfview
NVFINC = $(NVFDIR)\include
NVFLIB = $(NVFDIR)\lib

NIFF2NVF = $(NVFDIR)\niff2nvf

SRCDIR = src
INCDIR = include
OBJDIR = build
DATADIR = data
MODELDIR = $(DATADIR)\models

TARGET = test

CODEFILES = $(wildcard $(SRCDIR)\*.c) 
CODEOBJECTS = $(subst $(SRCDIR),$(OBJDIR),$(CODEFILES:.c=.o)) $(NUOBJ)

MODELFILES = $(wildcard $(MODELDIR)\*.niff)
MODELOBJECTS = $(subst $(MODELDIR),$(OBJDIR),$(MODELFILES:.niff=.nvf))

DEBUGSYM = -g
OPTIMIZER = -O0

NUSYSDIR = $(N64KITDIR)\nusys
NUSYSINC = $(NUSYSDIR)\include
NUSYSLIB = $(NUSYSDIR)\lib

NUOBJ = $(NUSYSLIB)\nusys.o

LCINCS = -I$(INC)\PR -I$(NUSYSINC) -I$(NVFINC) -I$(INCDIR)
LCOPTS = -G 0 $(DEBUGSYM)
LDFLAGS = -L$(ROOT)\usr\lib -L$(ROOT)\usr\lib\PR -L$(NUSYSLIB) -L$(NVFLIB) -lnusys_d -lgultra_d -L$(GCCDIR)\mipse\lib -lkmc -lmgk

include $(ROOT)\usr\include\make\PRdefs

CODESEGMENT = $(OBJDIR)\codesegment.o
SYMBOL = $(OBJDIR)\$(TARGET).out
ROM = $(OBJDIR)\$(TARGET).n64

default: $(ROM)

$(OBJDIR)\%.nvf: $(MODELDIR)\%.niff
	$(NIFF2NVF) $< $@

$(OBJDIR)\%.o: $(SRCDIR)\%.c
	$(CC) $(CFLAGS) $< -o $@

$(CODESEGMENT):	$(MODELOBJECTS) $(CODEOBJECTS)
	$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(ROM):	$(CODESEGMENT)
	$(MAKEROM) spec -I$(NUSYSINC) -r $(ROM) -e $(SYMBOL)
