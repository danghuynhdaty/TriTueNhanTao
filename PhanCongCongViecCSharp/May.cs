using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhanCongCongViecCSharp
{
    public class May
    {
        public int ChiSo { get; set; }

        public int TongThoiGian
        {
            set
            {
                TongThoiGian = 0;
            }
            get
            {
                int result = 0;
                foreach (var item in CongViecs)
                {
                    result += item.ThoiGian;
                }

                return result;
            }
        }

        public May(int chiSo)
        {
            ChiSo = chiSo;
            CongViecs = new List<CongViec>();
        }

        public List<CongViec> CongViecs { get; set; }

        public void ThemCongViec(CongViec cv)
        {
            CongViecs.Add(cv);
        }

        public void Xuat()
        {
            Console.WriteLine("May: {0} \nTong thoi gian: {1}", ChiSo, TongThoiGian);
            string str = "Cong viec: ";
            foreach (var item in CongViecs)
            {
                str += "\t" + item.ThoiGian;
            }
            Console.WriteLine(str);
            Console.WriteLine();
        }
    }
}