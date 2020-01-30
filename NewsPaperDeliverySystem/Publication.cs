using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewsPaperDeliverySystem
{
    public class Publication
    {
        private int id;
        private string name;
        private string genre;
        private int price;

       public Publication() { }
        public Publication(int idIN,string nameIN,string genereIN, int priceIN)
        {
            Name = nameIN;
            genre = genereIN;
            price = priceIN;
            id = idIN;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Genre
        {
            get { return genre; }
            set { genre = value; }
        }

        public int Price
        {
            get { return price; }
            set { price = value; }
        }

        public int ID
        {
            get { return id; }
            set { id = value; }
        }

    }

   

}
