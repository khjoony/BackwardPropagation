#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Neuron
{
public:
    Neuron()
        : w_(2.0), b_(1.0)
    {}
    
    Neuron(const double& w_input, const double& b_input)
        : w_(w_input), b_(b_input)
    {}

public: //attributes
    double w_;     // weigth of an input
    double b_;     // bias

    double input_, output_;    // saved for back-propagation


public:     //  beHaviors
    double feedForward(const double& _input)
    {
       // output y = f(\sigma)
       // \sigma = w_ * input x + b
       // for multiple inputs,
       // \sigma = w0_ * x0_ + w1_ * x_1 ..... + b
       input_ = _input;
       
       const double sigma = w_ * input_ + b_;

       output_ = getAct(sigma);

       return output_;
    }

    void propBackward(const double& target)
    {
        const double alpha = 0.01;       // learning-rate

        const double grad = (output_ -target) * getActGrad(output_);

        w_ -= alpha * grad * input_;    // last input_ came from d(wx+b)/dw = x
        b_ -= alpha * grad * 1.0;       // last 1.0 came from d(wx+b)/db = 1.0
    }

    double getAct(const double& x)
    {
       // for linear or indentity activation functions
       return x;

       // ReLU max(0, x); 
       // return MAX2(0.0, x);
    }


    double getActGrad(const double& x)
    {
        // linear or indentity activation functions
        return 1.0;

        // ReLU if(x > 0.0) ? 1.0 : 0.0
    }

    void feedForwardAndPrint(const double& input)
    {
        cout << "Starting of input : " << input << "----------------------------"<< endl;
        cout << "w : " << this->w_ << "         b : " << this->b_<< endl;
        int num = 0;
        while(num < 2001)
        {
            num ++;
            propBackward(4.0);
            if(num % 20 == 0)
            {
                cout << "Training : " << num << "th " << endl;
                cout <<"input: "<<  input<< "      output :   " << feedForward(input)<< endl;
                cout << "w : " << this->w_ << "         b : " << this->b_<< endl;
            }
        }
        
    }


};
int main()
{
    //my_neuron.feedForwardAndPrint(2.0);

    for (double input = 0.0; input < 3.0; input += 1.0)
    {
        Neuron my_neuron(2.0, 1.0);
        my_neuron.feedForwardAndPrint(input);
    }
    return 0;
}
