#include "include.h"

namespace Impulse {

    namespace Dataset {

        DatasetSample::DatasetSample(T_StringVector vec) {
            this->rawData = vec;
        }

        DatasetSample::DatasetSample(T_StringVector *vec) {
            this->rawData = T_StringVector(vec->begin(), vec->end());
        }

        DatasetSample::DatasetSample(T_DoubleVector vec) {
            for (T_Size i = 0; i < vec.size(); i++) {
                this->rawData.push_back(std::to_string(vec.at(i)));
            }
        }

        DatasetSample::DatasetSample(std::initializer_list<double> list) {
            for (auto i = list.begin(); i != list.end(); i++) {
                this->rawData.push_back(std::to_string(*i));
            }
        }

        void DatasetSample::out() {
            for (T_Size i = 0; i < this->rawData.size() - 1; i++) {
                std::cout << this->rawData.at(i) << ',';
            }
            std::cout << this->rawData.at(this->rawData.size() - 1) << std::endl;
        }

        T_String DatasetSample::getColumnToString(int columnIndex) {
            return this->rawData.at(columnIndex);
        }

        double DatasetSample::getColumnToDouble(int columnIndex) {
            return std::stod(this->getColumnToString(columnIndex));
        }

        void DatasetSample::setColumn(int columnIndex, T_String value) {
            this->rawData.at(columnIndex) = value;
        }

        void DatasetSample::setColumn(int columnIndex, double value) {
            this->rawData.at(columnIndex) = std::to_string(value);
        }

        void DatasetSample::setColumn(int columnIndex,
                                      std::function<T_String(T_String)> callback) {
            this->rawData.at(columnIndex) = callback(this->rawData.at(columnIndex));
        }

        void DatasetSample::insertColumnAfter(int columnIndex, T_String value) {
            this->rawData.insert(this->rawData.begin() + columnIndex + 1, value);
        }

        void DatasetSample::removeColumnAt(int columnIndex) {
            this->rawData.erase(this->rawData.begin() + columnIndex);
        }

        T_Size DatasetSample::getSize() {
            return this->rawData.size();
        }

        Impulse::Dataset::DatasetSample DatasetSample::copy() {
            T_StringVector copiedData(this->rawData);
            Impulse::Dataset::DatasetSample result(copiedData);
            return result;
        }

        T_DoubleVector DatasetSample::exportToDoubleVector() {
            T_DoubleVector result;
            for (T_Size i = 0; i < this->getSize(); i++) {
                result.push_back(this->getColumnToDouble(i));
            }
            return result;
        }

        Eigen::VectorXd DatasetSample::exportToEigen() {
            Eigen::VectorXd result(this->getSize());
            for (T_Size i = 0; i < this->getSize(); i++) {
                result(i) = this->getColumnToDouble(i);
            }
            return result;
        }
    }
}
