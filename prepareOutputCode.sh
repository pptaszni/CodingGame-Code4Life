echo "" > output.cpp
cat inc/Logger.hpp >> output.cpp
cat inc/Molecules.hpp >> output.cpp
cat inc/Robot.hpp | grep -v '#include "' >> output.cpp
cat inc/Sample.hpp | grep -v '#include "' >> output.cpp
cat inc/GameController.hpp | grep -v '#include "' >> output.cpp
cat src/Robot.cpp | grep -v '#include "' >> output.cpp
cat src/Sample.cpp | grep -v '#include "' >> output.cpp
cat src/GameController.cpp | grep -v '#include "' >> output.cpp
cat src/main.cpp | grep -v '#include "' >> output.cpp