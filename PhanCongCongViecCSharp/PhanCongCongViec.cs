using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhanCongCongViecCSharp
{
    public class PhanCongCongViec
    {
        private int soMay, soCongViec;

        private May[] mays;

        private CongViec[] congViecs;

        public void KhoiTao()
        {
            Console.Write("Nhap vao so may: ");
            soMay = int.Parse(Console.ReadLine());

            mays = new May[soMay];

            for (int i = 0; i < soMay; i++)
            {
                mays[i] = new May(i);
            }

            Console.Write("Nhap vao so cong viec: ");
            soCongViec = int.Parse(Console.ReadLine());

            congViecs = new CongViec[soCongViec];

            for (int i = 0; i < soCongViec; i++)
            {
                congViecs[i] = new CongViec(i);
                congViecs[i].Nhap();
            }

            SapXepCongViec(ref congViecs);

            for (int i = 0; i < soCongViec; i++)
            {
                congViecs[i].Xuat();
            }
        }

        private void SapXepCongViec(ref CongViec[] cv)
        {
            for (int i = 0; i < soCongViec - 1; i++)
            {
                for (int j = i + 1; j < soCongViec; j++)
                {
                    if (cv[i].ThoiGian < cv[j].ThoiGian)
                    {
                        CongViec temp = new CongViec(cv[i].ChiSo, cv[i].ThoiGian);
                        cv[i].ThoiGian = cv[j].ThoiGian;
                        cv[i].ChiSo = cv[j].ChiSo;

                        cv[j].ThoiGian = temp.ThoiGian;
                        cv[j].ChiSo = temp.ChiSo;
                    }
                }
            }
        }

        public void PhanCong()
        {
            for (int i = 0; i < soCongViec; i++)
            {
                int mayRanhRoi = MayRanhRoi();
                mays[mayRanhRoi].ThemCongViec(congViecs[i]);
            }
            for (int i = 0; i < soMay; i++)
            {
                mays[i].Xuat();
            }
        }

        private int MayRanhRoi()
        {
            int mayRanhRoi = 0;
            for (int i = 1; i < soMay; i++)
            {
                if (mays[i].TongThoiGian < mays[mayRanhRoi].TongThoiGian)
                {
                    mayRanhRoi = i;
                }
            }
            return mayRanhRoi;
        }
    }
}