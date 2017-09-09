#ifndef IMPULSE_DATASET_DATASETMODIFIER_DATASETSLICER_H
#define IMPULSE_DATASET_DATASETMODIFIER_DATASETSLICER_H

#include "../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        struct SlicedDataset {
            Dataset input;
            Dataset output;

            Eigen::MatrixXd *getInput() {
                if (this->inputVector.rows() == 0) {
                    this->inputVector.resize(this->input.getSize(), this->input.getSampleAt(0)->getSize());
                    for (T_Size i = 0; i < this->input.getSize(); i++) {
                        this->inputVector.row(i) = this->input.getSampleAt(i)->exportToEigen();
                    }
                }

                return &this->inputVector;
            }

            Eigen::MatrixXd *getOutput() {
                if (this->outputVector.rows() == 0) {
                    this->outputVector.resize(this->output.getSize(), this->output.getSampleAt(0)->getSize());
                    for (T_Size i = 0; i < this->output.getSize(); i++) {
                        this->outputVector.row(i) = this->output.getSampleAt(i)->exportToEigen();
                    }
                }
                return &this->outputVector;
            }

            Eigen::MatrixXd inputVector;
            Eigen::MatrixXd outputVector;
        };

        namespace DatasetModifier {

            class DatasetSlicer {
            protected:
                Dataset *dataset;
                std::vector<int> inputColumns;
                std::vector<int> outputColumns;
            public:
                DatasetSlicer(Dataset *_dataset);

                void addInputColumn(int columnIndex);

                void addOutputColumn(int columnIndex);

                SlicedDataset slice();
            };
        }
    }
}

#endif//