#ifndef BANDIT_CONTEXT_H
#define BANDIT_CONTEXT_H

namespace bandit {
  namespace detail {

    using namespace std;

    class context
    {
      public:
        void register_before_each(voidfunc_t func)
        {
          before_eaches_.push_back(func);
        }

        void run_before_eaches()
        {
          for_each(before_eaches_.begin(), 
                   before_eaches_.end(), 
                   [](voidfunc_t be){
                     be();
                   });
        }

      private:
        list<voidfunc_t> before_eaches_;
    };
    typedef deque<context*> contextstack_t;

    inline contextstack_t& context_stack()
    {
      static contextstack_t contexts;
      return contexts;
    }
  }
}

#endif