cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME test)				 # задать константу с именем проекта		 
project("${PROJECT_NAME}")			 # имя проекта	


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")			 # указываем, где искать файлы заголовков

add_executable("${PROJECT_NAME}" lab6_1.cpp
								 inc/func.hpp
								 src/func.cpp)	# добавить исполняемый файл
								 
file(COPY input.txt DESTINATION "/")	# скопировать файлы .txt в корневую папку проекта
file(COPY output.txt DESTINATION "/")