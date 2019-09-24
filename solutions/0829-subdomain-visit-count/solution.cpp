class Solution {
public:
    template<char delimiter>
    class DomainDots:public std::string
    {
     public:
        DomainDots() = default;
        DomainDots(std::string& str)
            : string(str)
        {
        }
    };
    template<char delimiter> 
    friend std::istream& operator>>(std::istream& is, DomainDots<delimiter>& dds)
    {
        std::getline(is, dds, '.');
        return is;
    }


    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<string, unsigned int> dc;
        vector<string> lOut;
        for ( auto i: cpdomains )
        {
            std::istringstream iss(i);
            // Split count & domain.
            vector<string> firstRes(std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>());
            if ( firstRes.size() > 2 || firstRes.size() <= 0 )
                throw std::invalid_argument("Not in [<count> <domain>] format");
            int count = std::stoi(firstRes[0]);
            std::istringstream iss2(firstRes[1]);
            DomainDots<'.'> domain(firstRes[1]);
            vector<string> dv ( (std::istream_iterator<DomainDots<'.'>>(iss2) ) ,
                                std::istream_iterator<DomainDots<'.'>>());
            // Last will be org/com .etc. Start from there.
            std::stringstream domss;
            for ( auto itr = dv.rbegin(); itr != dv.rend(); ++itr )
            {
                if ( domss.tellp() == 0 )
                    domss << *itr;
                else
                {
                    string copy(domss.str());
                    domss.seekp(0);
                    domss << *itr;
                    domss << ".";
                    domss << copy;
                }
                auto findItr = dc.find(domss.str());
                std::cout << " Now dom: " << domss.str() << std::endl;
                if ( findItr != dc.end() )
                {
                    findItr->second += count;//count
                }
                else
                {
                    dc[domss.str()] = count;
                }
            }
        }
        for ( auto mItr = dc.begin(); mItr != dc.end(); ++mItr)
        {
            std::string ds = std::to_string(mItr->second) + std::string(" ") + mItr->first ;
            lOut.push_back(ds);
        }

        dc.clear();
        return lOut;
    }
};
