#ifndef SRC_IMPULSE_DATASETSLICER_H_
#define SRC_IMPULSE_DATASETSLICER_H_

#include <vector>
#include <algorithm>
#include <cstdarg>
#include <string>
#include "../Dataset.h"

namespace Impulse {

struct SlicedDataset {
	Impulse::Dataset input;
	Impulse::Dataset output;
};

class DatasetSlicer {
protected:
	Impulse::Dataset * dataset;
	std::vector<int> inputColumns;
	std::vector<int> outputColumns;
public:
	DatasetSlicer(Impulse::Dataset * _dataset);
	void addInputColumn(int columnIndex);
	void addOutputColumn(int columnIndex);
	Impulse::SlicedDataset slice();
};

}

#endif /* SRC_IMPULSE_DATASETSLICER_H_ */
