#include "../include.h"


namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            DatasetSlicer::DatasetSlicer(Dataset *_dataset) :
                    dataset(_dataset) {

            }

            SlicedDataset DatasetSlicer::slice() {
                Dataset input;
                Dataset output;

                DatasetData *samples = this->dataset->getSamples();

                for (T_Size i = 0; i < samples->size(); i++) {
                    DatasetSample oldSample = samples->at(i);
                    T_StringVector newInputSampleData;
                    T_StringVector newOutputSampleData;

                    T_Size j;

                    for (j = 0; j < this->inputColumns.size(); j++) {
                        newInputSampleData.push_back(
                                oldSample.getColumnToString(this->inputColumns.at(j)));
                    }
                    DatasetSample newInputSample(newInputSampleData);
                    input.addSample(newInputSample);

                    for (j = 0; j < this->outputColumns.size(); j++) {
                        newOutputSampleData.push_back(
                                oldSample.getColumnToString(this->outputColumns.at(j)));
                    }

                    DatasetSample newOutputSample(newOutputSampleData);
                    output.addSample(newOutputSample);
                }

                SlicedDataset result;
                result.input = input;
                result.output = output;

                return result;
            }

            void DatasetSlicer::addInputColumn(int columnIndex) {
                this->inputColumns.push_back(columnIndex);
            }

            void DatasetSlicer::addOutputColumn(int columnIndex) {
                this->outputColumns.push_back(columnIndex);
            }

        }
    }

}
