#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

struct Connection {
	double weight;
	double deltaWeight;
};

class Neuron; //forward reference

typedef vector<Neuron> Layer;


//* * * * * * * * * Neuron * * * * * * * * * * // forward reference

class Neuron () {
public:
	Neuron(unsigned numOutputs);
	void setOutputVal(double val) {	m_outputVal = val; }
	double getOutputVal(void) const  {return m_outputVal; }
	void feedForward const (Layer &prevLayer);
private:
	static double randomWeight(void) { return rand() / (double RAND_MAX); }
	double m_outputVal;
	vector<Connection> m_outputWeights;
};

Neuron::Neuron(unsigned numOutputs) {
	for (unsigned c = 0; c < numOutputs; ++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
}

void Neuron::feedForward(const Layer &prevLayer) {
	double sum = 0.0;

	//Sum the previous layer's outputs (which are our inputs)
	//Include the bias node from the previous layer

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		sum += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights[?].weight;
	}
}

//* * * * * * * * * Net * * * * * * * * * * * *//



class Net {
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals) {};
	void backProp(const vector<double> &targetVals) {};
	void getResults(vector <double> &resultVals) const {};

private:
	vector<Layer> m_layers;//m_layers[layerNum][neuronNum]
};

void Net::feedForward(const vector<double> &inputVals) {
	assert(inputVals.size() == m_layers[0].size() - 1);

	for (unsigned i = 0; i < inputVals.size(); ++i) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	//forward propogate

	for (unsigned layerNum = 0; layerNum < m_layers.size(); ++layerNum) {
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n )
	}

};


Net::Net(const vector<unsigned> &topology) {	
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0: topology[layerNum + 1];
		//We have made a new Layer, now fill it with neurons and 
		//add a bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs));
			cout << "Made a Neuron!~" << endl;
		}
	}
}

int main() {
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	Net myNet(topology);


	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);
	
	vector<double> resultVals;
	myNet.getResults(resultVals);
}