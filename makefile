# Compiler
CXX = g++

# Options du compilateur
CXXFLAGS = -std=c++11 -Wall -Wextra -Iutil -Iobjects -IDao -IServices -lm

# Répertoires
SRCDIR_DAO = Dao
SRCDIR_OBJ = objects
SRCDIR_SERV = Services
SRCDIR_VIEW = Views
SRCDIR_MAIN = .

OBJDIR = CompilerFiles

# Fichiers source
SRCS_DAO = $(wildcard $(SRCDIR_DAO)/*.cpp)
SRCS_VIEW = $(wildcard $(SRCDIR_VIEW)/*.cpp)
SRCS_OBJ = $(wildcard $(SRCDIR_OBJ)/*.cpp)
SRCS_SERV = $(wildcard $(SRCDIR_SERV)/*.cpp)
SRCS_MAIN = $(wildcard $(SRCDIR_MAIN)/main.cpp)

# Fichiers objets
OBJS_DAO = $(patsubst $(SRCDIR_DAO)/%.cpp, $(OBJDIR)/%.o, $(SRCS_DAO))
OBJS_VIEW = $(patsubst $(SRCDIR_VIEW)/%.cpp, $(OBJDIR)/%.o, $(SRCS_VIEW))
OBJS_OBJ = $(patsubst $(SRCDIR_OBJ)/%.cpp, $(OBJDIR)/%.o, $(SRCS_OBJ))
OBJS_SERV = $(patsubst $(SRCDIR_SERV)/%.cpp, $(OBJDIR)/%.o, $(SRCS_SERV))
OBJS_MAIN = $(patsubst $(SRCDIR_MAIN)/%.cpp, $(OBJDIR)/%.o, $(SRCS_MAIN))

# Nom de l'exécutable
TARGET = main

# Règles
all: $(OBJS_DAO) $(OBJS_OBJ) $(OBJS_SERV) $(OBJS_VIEW) $(OBJS_MAIN)
	$(CXX) -o $(TARGET) $(OBJS_DAO) $(OBJS_OBJ) $(OBJS_SERV) $(OBJS_VIEW) $(OBJS_MAIN)

$(OBJDIR)/%.o: $(SRCDIR_DAO)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR_OBJ)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR_SERV)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR_VIEW)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR_MAIN)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cibles de nettoyage
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
