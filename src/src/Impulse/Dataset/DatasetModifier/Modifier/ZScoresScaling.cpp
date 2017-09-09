#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void ZScoresScaling::applyToColumn(int columnIndex) {
                    DatasetData *samples = this->dataset->getSamples();
                    T_Size i;
                    double sum;
                    double mean;
                    double count = 0.0;
                    double variance = 0.0;
                    double standardDeviation;

                    for (i = 0; i < samples->size(); i++) {
                        double value = samples->at(i).getColumnToDouble(columnIndex);
                        sum += value;
                        count += 1.0;
                    }

                    mean = sum / count;

                    for (i = 0; i < samples->size(); i++) {
                        double value = samples->at(i).getColumnToDouble(columnIndex);
                        variance += pow(value - mean, 2.0);
                    }

                    standardDeviation = sqrt((1.0 / count) * variance);

                    for (i = 0; i < samples->size(); i++) {
                        double value = samples->at(i).getColumnToDouble(columnIndex);
                        double newValue = (value - mean) / standardDeviation;
                        samples->at(i).setColumn(columnIndex, newValue);
                    }

                    this->data["mean"][columnIndex] = std::to_string(mean);
                    this->data["standardDeviation"][columnIndex] = std::to_string(
                            standardDeviation);
                }

                T_DoubleVector ZScoresScaling::applyToSample(
                        std::initializer_list<double> list) {
                    T_DoubleVector result;
                    for (auto i = list.begin(); i != list.end(); i++) {
                        result.push_back(*i);
                    }
                    for (T_Size j = 0; j < result.size(); j++) {
                        double mean = std::stod(this->data["mean"][j]);
                        double standardDeviation = std::stod(
                                this->data["standardDeviation"][j]);
                        result.at(j) = ((result.at(j) - mean) / standardDeviation);
                    }
                    return result;
                }

            }

        }
    }
}