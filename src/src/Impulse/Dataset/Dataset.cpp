#include "include.h"

namespace Impulse {

    namespace Dataset {

        Dataset::~Dataset() {
            this->data.clear();
        }

        void Dataset::addSample(DatasetSample sample) {
            this->data.push_back(sample);
        }

        void Dataset::addSample(DatasetSample *sample) {
            this->data.push_back(sample->copy());
        }

        void Dataset::out(T_Size limit) {
            for (T_Size i = 0; i < this->data.size(); i++) {
                if (limit > 0)
                    if (i + 1 == limit)
                        break;

                this->data.at(i).out();
            }
            std::cout << "---" << std::endl;
        }

        DatasetData *Dataset::getSamples() {
            return &this->data;
        }

        DatasetSample *Dataset::getSampleAt(int index) {
            return &this->data.at(index);
        }

        T_Size Dataset::getSize() {
            return this->data.size();
        }

        T_Size Dataset::getColumnsSize() {
            if (this->getSize() > 0) {
                return this->data.at(0).getSize();
            }
            return 0;
        }
    }
}
