cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/src/Impulse/Dataset)
include_directories(src/src/Impulse/Dataset/DatasetBuilder)
include_directories(src/src/Impulse/Dataset/DatasetModifier)
include_directories(src/src/Impulse/Dataset/DatasetModifier/Modifier)

project(impulse-ml-dataset-slicer)
add_executable(impulse-ml-dataset-slicer
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.h
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.cpp
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.h
        src/src/Impulse/Dataset/common.cpp
        src/src/Impulse/Dataset/common.h
        src/src/Impulse/Dataset/Dataset.cpp
        src/src/Impulse/Dataset/Dataset.h
        src/src/Impulse/Dataset/DatasetExporter.cpp
        src/src/Impulse/Dataset/DatasetExporter.h
        src/src/Impulse/Dataset/DatasetSample.cpp
        src/src/Impulse/Dataset/DatasetSample.h
        src/src/Impulse/Dataset/include.h
        src/impulse-ml-dataset-slicer.cpp)

project(impulse-ml-dataset-modifier)
add_executable(impulse-ml-dataset-modifier
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.h
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.cpp
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.h
        src/src/Impulse/Dataset/common.cpp
        src/src/Impulse/Dataset/common.h
        src/src/Impulse/Dataset/Dataset.cpp
        src/src/Impulse/Dataset/Dataset.h
        src/src/Impulse/Dataset/DatasetExporter.cpp
        src/src/Impulse/Dataset/DatasetExporter.h
        src/src/Impulse/Dataset/DatasetSample.cpp
        src/src/Impulse/Dataset/DatasetSample.h
        src/src/Impulse/Dataset/include.h
        src/impulse-ml-dataset-modifier.cpp)

project(impulse-ml-dataset-spliter)
add_executable(impulse-ml-dataset-spliter
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.h
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.cpp
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.h
        src/src/Impulse/Dataset/common.cpp
        src/src/Impulse/Dataset/common.h
        src/src/Impulse/Dataset/Dataset.cpp
        src/src/Impulse/Dataset/Dataset.h
        src/src/Impulse/Dataset/DatasetExporter.cpp
        src/src/Impulse/Dataset/DatasetExporter.h
        src/src/Impulse/Dataset/DatasetSample.cpp
        src/src/Impulse/Dataset/DatasetSample.h
        src/src/Impulse/Dataset/include.h
        src/impulse-ml-dataset-spliter.cpp)
