#include "../../include.h"


namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void MissingData::setModificationType(T_String type) {
                    this->modificationType = type;
                }

                void MissingData::applyToColumn(int columnIndex) {
                    double sum = 0;
                    std::vector<int> rowsToFill;
                    DatasetData *samples = this->dataset->getSamples();
                    T_Size i;
                    T_Size j = 0;
                    double valueToFill;

                    for (i = 0; i < samples->size(); i++) {
                        DatasetSample *sample = &samples->at(i);
                        T_String columnValue = sample->getColumnToString(columnIndex);
                        if (columnValue.length() > 0) {
                            sum += sample->getColumnToDouble(columnIndex);
                            j++;
                        } else {
                            rowsToFill.push_back(i);
                        }
                    }

                    if (this->modificationType == "mean") {
                        valueToFill = sum / j;
                    }

                    for (i = 0; i < rowsToFill.size(); i++) {
                        Impulse::Dataset::DatasetSample *sample = this->dataset->getSampleAt(rowsToFill.at(i));
                        sample->setColumn(columnIndex, valueToFill);
                    }
                }

            }

        }
    }

}
