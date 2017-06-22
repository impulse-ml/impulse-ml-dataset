#ifndef SRC_IMPULSE_DATASETMODIFIER_BASEDATASETMODIFIER_H_
#define SRC_IMPULSE_DATASETMODIFIER_BASEDATASETMODIFIER_H_

#include <string>
#include <functional>
#include "../Dataset.h"

namespace Impulse {

namespace DatasetModifier {

class BaseDatasetModifier {
protected:
	Impulse::Dataset * dataset;
public:
	BaseDatasetModifier(Impulse::Dataset * dataset);
	virtual ~BaseDatasetModifier() {
	}
	void applyToAll();
	virtual void applyToColumn(int columnIndex) = 0;
};

}

}

#endif /* SRC_IMPULSE_DATASETMODIFIER_BASEDATASETMODIFIER_H_ */
