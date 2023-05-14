using System;
using System.Collections.Generic;
using System.Linq;

namespace lab4
{
    struct Mail
    {
        private string city;
        private string street;
        private int houseNum;
        private int apartmentNum;
        private string reciever;
        private double cost;

        public static List<Mail> MailObjects = new List<Mail>();

        public Mail(
            string city = "Unknown",
            string street = "Unknown",
            int houseNum = 0,
            int apartmentNum = 0,
            string reciever = "Unknown",
            double cost = 0)
        {
            this.city = city;
            this.street = street;
            this.houseNum = houseNum;
            this.apartmentNum = apartmentNum;
            this.reciever = reciever;
            this.cost = cost;
            MailObjects.Add(this);
        }

        public static void CheckMailsFrom(string[] cities)
        {
            for (int i = 0; i < cities.Length; i++)
            {
                if (MailObjects.Any(mail => mail.city == cities[i]))
                {
                    Console.WriteLine($"В городе {cities[i]} имеются посылки");
                }
                else Console.WriteLine($"В городе {cities[i]} посылок НЕТ");
            }
        }

        private static bool CompareMailAdresses(Mail mail1, Mail mail2)
        {
            return (mail1.city == mail2.city &&
                    mail1.street == mail2.street &&
                    mail1.houseNum == mail2.houseNum &&
                    mail1.apartmentNum == mail2.apartmentNum);
        }

        public static void FindMailsWithSameAdresses()
        {
            List<Mail> mailList = MailObjects;
            HashSet<string> recievers = new HashSet<string>();

            while (mailList.Count() != 0)
            {
                int counter = 0;
                Mail temp = mailList[0];

                for (int i = 1; i < mailList.Count(); i++)
                { 
                    if (CompareMailAdresses(mailList[0], mailList[i]))
                    {
                        counter++;
                        recievers.Add(mailList[i].reciever);
                        mailList.RemoveAt(i);
                        i--;
                    }
                }
                mailList.RemoveAt(0);

                if (counter > 0)
                {
                    recievers.Add(temp.reciever);
                    Console.WriteLine($"По адресу: " +
                        $"{temp.city}, {temp.street}, " +
                        $"{temp.houseNum}, {temp.apartmentNum} " +
                        $"было получено {counter + 1} посылки(ок)");
                    Console.WriteLine("Получатели:");

                    foreach (string reciever in recievers)
                    {
                        Console.WriteLine(reciever);
                    }
                }
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            string[] cities = {"Калининград", "Гомель", "Слуцк"};
            Mail mail1 = new Mail("Слуцк", "Гомельская", 74, 35, "Глущенко В.В.", 30);
            Mail mail2 = new Mail("Гомель", "Гомельская", 74, 35, "Глуще", 30);
            Mail mail3 = new Mail("Гомель", "Гомельская", 74, 35, "Глуще", 30);
            Mail.CheckMailsFrom(cities);
            Mail.FindMailsWithSameAdresses();
        }
    }
}