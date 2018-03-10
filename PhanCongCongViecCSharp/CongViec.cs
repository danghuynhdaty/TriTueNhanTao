using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhanCongCongViecCSharp
{
    public class CongViec
    {
        public CongViec(int chiSo)
        {
            ChiSo = chiSo;
        }

        public CongViec(int chiSo, int thoiGian) : this(chiSo)
        {
            ThoiGian = thoiGian;
        }

        public int ChiSo { get; set; }

        public int ThoiGian { get; set; }

        public void Nhap()
        {
            Console.Write("Thoi gian cho cong viec: ");
            ThoiGian = int.Parse(Console.ReadLine());
        }

        public void Xuat()
        {
            Console.WriteLine("Cong viec: {0} \tthoi gian: {1} ", ChiSo, ThoiGian);
        }
    }
}