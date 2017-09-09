cmake_minimum_required(VERSION 3.7)
project(impulse_ml_dataset)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.h
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.cpp
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.h
        src/src/Impulse/Dataset/Dataset.cpp
        src/src/Impulse/Dataset/Dataset.h
        src/src/Impulse/Dataset/DatasetSample.cpp
        src/src/Impulse/Dataset/DatasetSample.h
        src/main.cpp src/src/Impulse/Dataset/include.h src/src/Impulse/Dataset/common.h)

add_executable(impulse_ml_dataset ${SOURCE_FILES})