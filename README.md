# Dron Podwodny - Underwater Drone

## 🎥 Demo Video

[![Watch the video](https://img.youtube.com/vi/O7o0BTiswNI/maxresdefault.jpg)](https://youtu.be/O7o0BTiswNI)

_Click the image to watch the demo video!_

A C++ program that allows you to **steer an underwater drone** with graphical visualization using **Gnuplot**.

### 👨‍💻 Made by: Tomasz Pijanowski

## 🎨 Visualization with Gnuplot

This program utilizes **[Gnuplot](http://www.gnuplot.info/)** for graphical representation.

For data transfer between **C++** and **Gnuplot**, it uses **Łącze do GNUplota**:\
📚 [Documentation](https://kcir.pwr.edu.pl/~kreczmer/kpo/materialy/dodatki/lacze_do_gnuplota/doc/doxygen/index.html)

---

## 🛠️ Prerequisites

Ensure you have the following installed before running the program:

- **[Gnuplot](http://gnuplot.info/)** (for visualization)

### Install Gnuplot:

#### macOS:

```sh
brew install gnuplot
```

#### Ubuntu/Debian:

```sh
sudo apt update && sudo apt install gnuplot
```

#### Windows:

Download and install from [gnuplot.info](http://www.gnuplot.info/).

---

## 💽 Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/browner342/DronPodwodny.git
   ```

2. **Navigate to the project directory:**

   ```sh
   cd DronPodwodny/project
   ```

3. **Build the program using ********`make`********:**

   ```sh
   make
   ```

4. **Run the program:**

   ```sh
   ./dron-podwodny
   ```

---

## 🎮 Usage

After running the program:

```sh
$ ./dron-podwodny
Twoj wybor, m - menu >
```

### 📌 Available Commands:

- **`m`** → Show menu
- **`r`** → Move forward and set an angle (up/down)
- **`o`** → Rotate the drone (set turning angle)
- **`k`** → Exit the program

### Example Usage:

#### 📍 Moving Forward (`r`)

```sh
Twoj wybor, m - menu > r
Podaj kat wznoszenia/opadania w stopniach.  // Enter the ascent/descent angle.
Wartosc kata > 30

Podaj wartosc przemieszczenia drona.        // Enter the displacement.
Wartosc odleglosci > 10

Aktualna ilosc obiektow Wektor3D > 1725     // Current number of Vectors
Laczna ilosc obiektow > 59902               // Total number of Vectors created
```

#### 🔄 Rotating the Drone (`o`)

```sh
Twoj wybor, m - menu > o
Podaj wartosc kata obrotu w stopniach.      // Enter the rotation angle.
Podaj kat obrotu: 30

Aktualna ilosc obiektow Wektor3D > 1725     // Current number of Vectors
Laczna ilosc obiektow > 169382              // Total number of Vectors created
```

---

## 📚 License

This project is licensed under the **MIT License**.
