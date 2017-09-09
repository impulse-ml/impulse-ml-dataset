#ifndef IMPULSE_DATASET_DATASETSAMPLE_H
#define IMPULSE_DATASET_DATASETSAMPLE_H

#include "include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        class DatasetSample {
        protected:
            T_StringVector rawData;
        public:
            DatasetSample(T_StringVector vec);

            DatasetSample(T_StringVector *vec);

            DatasetSample(T_DoubleVector vec);

            DatasetSample(std::initializer_list<double> list);

            void out();

            T_String getColumnToString(int columnIndex);

            double getColumnToDouble(int columnIndex);

            void setColumn(int columnIndex, T_String value);

            void setColumn(int columnIndex, double value);

            void setColumn(int columnIndex,
                           std::function<T_String(T_String)> callback);

            void insertColumnAfter(int columnIndex, T_String value);

            void removeColumnAt(int columnIndex);

            T_Size getSize();

            DatasetSample copy();

            T_DoubleVector exportToDoubleVector();

            Eigen::VectorXd exportToEigen();
        };
    }
}

#endif//IMPULSE_DATASET_DATASETSAMPLE_H