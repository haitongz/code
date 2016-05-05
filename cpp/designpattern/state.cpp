#include <iostream>
using namespace std;
class Work;
class State
{
public:
  virtual void Operation(Work *work)
  {
  }
};

class Work
{
public:
  Work (State *state): m_state(state), m_step(0)
  {
  }
  ~Work ()
  {
    delete m_state;
  }

  int GetStep()
  {
    return m_step;
  }

  void SetStep(int step)
  {
    m_step = step;
  }

  void SetState(State *state)
  {
    delete m_state;
    m_state = state;
  }

  void Operation()
  {
    m_state->Operation(this);
  }

private:
  State *m_state;
  int m_step;
};

class ExhaustState: public State
{
public:
  void Operation(Work *work) // 排气操作
  {
    if (work->GetStep() == 4)
    {
      std::cout << "Step: " << work->GetStep() << "排气操作" << std::endl;
    }
  }
};
// 做功状态
class ActState: public State
{
public:
  void Operation(Work *work) // 排气操作
  {
    if (work->GetStep() == 3)
    {
      std::cout << "Step: " << work->GetStep() << "做功操作" << std::endl;
    }
    else
    {
      work->SetState(new ExhaustState());
      work->Operation();
    }
  }
};


// 压缩状态
class CompressState: public State
{
public:
  void Operation(Work *work) // 压缩操作
  {
    if (work->GetStep() == 2)
    {
      std::cout << "Step: " << work->GetStep() << "压缩操作" << std::endl;
    }
    else
    {
      work->SetState(new ActState());
      work->Operation();
    }
  }
};

// 吸气状态
class InhaleState: public State
{
public:
  void Operation(Work *work) // 吸气操作
  {
    if (work->GetStep() == 1)
    {
      std::cout << "Step: " << work->GetStep() << "吸气操作" << std::endl;
    }
    else
    {
      State *p = new CompressState();
      work->SetState(p);
      work->Operation();
    }
  }
};

int main(int argc, char *argv[])
{
  State* st = new InhaleState();
  Work *work = new Work(st);

  for (int i = 1; i < 5; ++i)
  {
    work->SetStep(i);
    work->Operation();
  }
  delete work;
  return 0;
}

// 定义：允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类。
// 使用范围：
// 1 一个对象的行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为。
// 2 一个操作中含有庞大的多分支的条件语句，且这些分支依赖于该对象的状态。
//
