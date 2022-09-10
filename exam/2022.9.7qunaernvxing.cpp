class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 翻牌
     * @param inHand string字符串 一组以单空格间隔的手牌(例如：SA HK H9 D8 C5 S5 H4)
     * @return string字符串
     */
    string showDown(string inHand)
    {
        // write code here
        vector<string> strs;
        string temp = "";
        for (int i = 0; i < inHand.size(); ++i)
        {
            if (inHand[i] == ' ')
            {
                strs.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(inHand[i]);
            }
        }
        if (temp.size())
            strs.push_back(temp);

        int n = strs.size();
        if (n < 5)
            return "GaoPai";
        int color[4] = {0};
        int num[13] = {0};
        int num_has_color[13][4] = {0};
        for (auto &e : strs)
        {
            int cur_color_index = 0;
            switch (e[0])
            {
            case 'S':
                color[0]++;
                cur_color_index = 0;
                break;
            case 'H':
                color[1]++;
                cur_color_index = 1;
                break;
            case 'C':
                color[2]++;
                cur_color_index = 2;
                break;
            case 'D':
                color[3]++;
                cur_color_index = 3;
                break;
            default:
                break;
            }
            if (isdigit(e[1]))
            {
                if (e[1] != '1')
                {
                    num[e[1] - '2']++;
                    num_has_color[e[1] - '2'][cur_color_index] = 1;
                }
                else
                {
                    num[8]++;
                    num_has_color[8][cur_color_index] = 1;
                }
            }
            else
            {
                switch (e[1])
                {
                case 'J':
                    num[9]++;
                    num_has_color[9][cur_color_index] = 1;
                    break;
                case 'Q':
                    num[10]++;
                    num_has_color[10][cur_color_index] = 1;
                    break;
                case 'K':
                    num[11]++;
                    num_has_color[11][cur_color_index] = 1;
                    break;
                case 'A':
                    num[12]++;
                    num_has_color[12][cur_color_index] = 1;
                    break;
                default:
                    break;
                }
            }
        }
        if (num[8] && num[9] && num[10] && num[11] && num[12])
        {
            for (int j = 0; j < 4; ++j)
            {
                if (num_has_color[8][j] && num_has_color[9][j] && num_has_color[10][j] && num_has_color[11][j] && num_has_color[12][j])
                {
                    return "HuangJiaTongHuaShun";
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            if (num[i] && num[(i + 1)] && num[(i + 2)] && num[(i + 3)] && num[(i + 4)])
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (num_has_color[i][j] && num_has_color[(i + 1)][j] && num_has_color[(i + 2)][j] && num_has_color[(i + 3)][j] && num_has_color[(i + 4)][j])
                    {
                        return "TongHuaShun";
                    }
                }
            }
        }
        if (num[12] && num[0] && num[1] && num[2] && num[3])
        {
            for (int j = 0; j < 4; ++j)
            {
                if (num_has_color[12][j] && num_has_color[0][j] && num_has_color[1][j] && num_has_color[2][j] && num_has_color[3][j])
                {
                    return "TongHuaShun";
                }
            }
        }
        for (int i = 0; i < 13; ++i)
        {
            if (num[i] >= 4)
                return "SiTiao";
        }

        bool hasThree = false, hashTwo = false;
        for (int i = 0; i < 13; ++i)
        {
            if (!hasThree && num[i] >= 3)
                hasThree = true;
            else if (!hashTwo && num[i] >= 2)
                hasThree = true;
            if (hasThree && hashTwo)
                return "HuLu";
        }
        if (color[0] >= 5 || color[1] >= 5 || color[2] >= 5 || color[3] >= 5)
        {
            return "TongHua";
        }
        for (int i = 0; i < 9; ++i)
        {
            if (num[i] && num[(i + 1)] && num[(i + 2)] && num[(i + 3)] && num[(i + 4)])
                return "ShunZi";
        }
        if (num[12] && num[0] && num[1] && num[2] && num[3])
        {
            return "ShunZi";
        }

        for (int i = 0; i < 13; ++i)
        {
            if (num[i] >= 3)
                return "SanTiao";
        }
        hashTwo = false;
        for (int i = 0; i < 13; ++i)
        {
            if (num[1] >= 2)
            {
                if (!hashTwo)
                    hashTwo = true;
                else
                    return "LiangDui";
            }
        }
        for (int i = 0; i < 13; ++i)
        {
            if (num[i] >= 2)
                return "YiDui";
        }
        return "GaoPai";
    }
};