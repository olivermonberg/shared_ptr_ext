#Constants
# Verion 1.0.0
SOURCES 	= main.cpp 
OBJECTS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.d))
EXE = program
HOST = linux


#Compiler setUp
CXX = g++ 
CXXFLAGS = -I. -Wall -std=c++17 	# -I. = path to include files '. mean here # -Wall Show all Possible warnins

#For windows 
ifeq (${HOST}, windows)
BUILD_DIR			= build/${HOST}
BIN_DIR 			= bin/${HOST}
CLEAN_CMD1 			= powershell Remove-Item -Path "${BUILD_DIR}" -Recurse
CLEAN_CMD2 			= powershell Remove-Item -Path "${BIN_DIR}" -Recurse
MAKE_FOLDER_BUILD 	= powershell ./CreateFolder.ps1 "${BUILD_DIR}"  
MAKE_FOLDER_BIN   	= powershell ./CreateFolder.ps1 "${BIN_DIR}"  
endif

#For linux
ifeq (${HOST}, linux)
BUILD_DIR			= build/${HOST}
BIN_DIR 			= bin/${HOST}
CXXFLAGS 			+= -pthread
CLEAN_CMD1 			= -rm -rf ${BUILD_DIR}  
CLEAN_CMD2			= -rm -rf ${BIN_DIR} 
MAKE_FOLDER			= mkdir -p
MAKE_FOLDER_BUILD 	= mkdir -p ${BUILD_DIR}  
MAKE_FOLDER_BIN   	= mkdir -p ${BIN_DIR}  
endif

all: info $(BIN_DIR)/$(EXE)

info:
	@ echo "Compiling for '${HOST}'..."
	
${BIN_DIR}/${EXE}:  ${DEPS} ${OBJECTS} 
	@ echo "Creating directory '${BIN_DIR}' if not exits"
	${MAKE_FOLDER_BIN} 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

${BUILD_DIR}/%.d: %.cpp
	@ echo "Creating directory '${BUILD_DIR}' if not exits"
	${MAKE_FOLDER_BUILD}
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $^ > $@

${BUILD_DIR}/%.o: %.cpp
	@ echo "Creating directory '${BUILD_DIR}' if not exits"
	${MAKE_FOLDER_BUILD}
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	${CLEAN_CMD1}
	${CLEAN_CMD2}
