using System;
using System.Threading;
using HtmlAgilityPack;


namespace webscrp {

    class Webscrp {

        public class funct {
            public string Getbtcp() {
                HtmlWeb webp = new HtmlWeb();
                HtmlDocument load = webp.Load("https://www.livecoinwatch.com/price/Bitcoin-BTC");
                var target = load.DocumentNode.SelectNodes("//span[@class='price']");
                foreach (var item in target) {
                    string ethp = item.InnerText;
                    return ethp;
                }
                return null;
            }

            public string Getethp() {
                HtmlWeb webp = new HtmlWeb();
                HtmlDocument load = webp.Load("https://www.livecoinwatch.com/price/Ethereum-ETH");
                var target = load.DocumentNode.SelectNodes("//span[@class='price']");
                foreach (var item in target) {
                    string ethp = item.InnerText;
                    return ethp;
                }
                return null;              
            }
        }
        static void Main(string[] args) {

            while (true) {
                    Console.Clear();
                    funct f = new funct { };
                    var a = f.Getbtcp();
                    var b = f.Getethp();

                    Console.WriteLine("[ webscrap test ]");
                    Console.WriteLine("-----------------------------");
                    Console.WriteLine("source: www.livecoinwatch.com");
                    Console.WriteLine("-----------------------------");
                    Console.WriteLine("btc price: " + a);
                    Console.WriteLine("eth price: " + b);

                    Console.WriteLine("-----------------------------");
                    Console.WriteLine("press any key to refresh");
                    Console.ReadLine();
                    //Thread.Sleep(500);
            };

        }

    }
}
