# impulse-ml

## impulse-ml-dataset

```cpp
#include "src/Impulse/Dataset/include.h"

using namespace Impulse::Dataset;

int main() {
    // build dataset from csv...
    DatasetBuilder::CSVBuilder builder(
            "/home/hud/eclipse-workspace/impulse-ml-dataset/src/data/data.csv");
    Dataset dataset = builder.build();
    dataset.out();

    // and start modification - slice to input-output pair
    DatasetModifier::DatasetSlicer datasetSlicer(&dataset);
    datasetSlicer.addInputColumn(0);
    datasetSlicer.addInputColumn(1);
    datasetSlicer.addInputColumn(2);
    datasetSlicer.addOutputColumn(3);

    SlicedDataset slicedDataset = datasetSlicer.slice();
    slicedDataset.input.out();
    slicedDataset.output.out();

    // fill missing data by mean of fields
    DatasetModifier::Modifier::MissingData missingDataModifier(
            &slicedDataset.input);
    missingDataModifier.setModificationType("mean");
    missingDataModifier.applyToColumn(1);
    missingDataModifier.applyToColumn(2);

    slicedDataset.input.out();

    DatasetModifier::Modifier::Category categoryModifier(
            &slicedDataset.input);
    categoryModifier.applyToColumn(0);

    slicedDataset.input.out();

    // convert last column "Yes/No" to numbers
    DatasetModifier::Modifier::Callback callbackModifier(
            &slicedDataset.output);
    callbackModifier.setCallback([](T_String oldValue) -> T_String {
        if (oldValue.find("Yes") != T_String::npos) {
            return "1";
        }
        return "0";
    });
    callbackModifier.applyToColumn(0);

    slicedDataset.output.out();

    // scale all input
    DatasetModifier::Modifier::ZScoresScaling zScoresModifier(
            &slicedDataset.input);

    zScoresModifier.apply();

    // we can split dataset by parts of given ratio
    DatasetModifier::DatasetSplitter datasetSplitter(&slicedDataset);
    SplittedDataset splittedDataset = datasetSplitter.split(0.8);

    splittedDataset.primary.input.out();
    splittedDataset.primary.output.out();
    splittedDataset.secondary.input.out();
    splittedDataset.secondary.output.out();

    return 0;
};
```