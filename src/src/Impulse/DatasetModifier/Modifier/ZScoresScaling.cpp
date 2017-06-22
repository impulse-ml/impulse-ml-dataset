#include "ZScoresScaling.h"

namespace Impulse {

namespace DatasetModifier {

namespace Modifier {

void ZScoresScaling::applyToColumn(int columnIndex) {
	DatasetData * samples = this->dataset->getSamples();
	unsigned int i;
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

	standardDeviation = sqrt((1 / count) * variance);

	for (i = 0; i < samples->size(); i++) {
		double value = samples->at(i).getColumnToDouble(columnIndex);
		double newValue = (value - mean) / standardDeviation;
		samples->at(i).setColumn(columnIndex, newValue);
	}
}

}

}

}
