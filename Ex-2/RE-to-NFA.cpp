#include <iostream>
#include <stack>
#include <vector>

struct NFA
{
    int start_state;
    int final_state;
};

NFA RegexToNFA(const std::string &regex)
{
    std::stack<NFA> nfa_stack;
    for (const char c : regex)
    {
        switch (c)
        {
        case '|':
        {
            NFA nfa2 = nfa_stack.top();
            nfa_stack.pop();
            NFA nfa1 = nfa_stack.top();
            nfa_stack.pop();
            int start_state = next_state++;
            int final_state = next_state++;
            nfa_stack.emplace(NFA{start_state, final_state});
            break;
        }
        case '*':
        {
            NFA nfa = nfa_stack.top();
            nfa_stack.pop();
            int start_state = next_state++;
            int final_state = next_state++;
            nfa_stack.emplace(NFA{start_state, final_state});
            break;
        }
        default:
        {
            int start_state = next_state++;
            int final_state = next_state++;
            nfa_stack.emplace(NFA{start_state, final_state});
            break;
        }
        }
    }
    return nfa_stack.top();
}

int main()
{
    std::string regex;
    std::cin >> regex;
    NFA nfa = RegexToNFA(regex);
    std::cout << "Start State: " << nfa.start_state << std::endl;
    std::cout << "Final State: " << nfa.final_state << std::endl;
    return 0;
}
