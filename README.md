# 🚗 Carrinho Wi-Fi com ESP8266

Este projeto permite controlar um **carrinho robô** utilizando um **módulo ESP8266 (NodeMCU)**.
Através de uma **interface web acessada por Wi-Fi**, você pode enviar comandos para mover o carrinho para frente, ré, esquerda, direita e parar.

---

## 📡 Funcionamento

O ESP8266 cria uma **rede Wi-Fi local (Access Point)** chamada `CarrinhoESP`, com senha `12345678`.
Ao conectar-se a essa rede, basta acessar o **IP padrão do ESP8266 (geralmente 192.168.4.1)** no navegador, e uma página de controle será exibida com botões para controlar o carrinho.

---

## 🧠 Recursos principais

* Controle via Wi-Fi (sem internet necessária)
* Interface Web simples com botões de direção
* Movimentos: Frente, Ré, Esquerda, Direita e Parar
* Código limpo e de fácil compreensão
* Compatível com motores controlados por ponte H (ex: L298N, L293D)

---

## ⚙️ Componentes necessários

| Componente                               | Quantidade | Descrição              |
| ---------------------------------------- | ---------- | ---------------------- |
| ESP8266 (NodeMCU)                        | 1          | Módulo Wi-Fi principal |
| Ponte H (L298N ou L293D)                 | 1          | Controla os motores    |
| Motor DC                                 | 2          | Motores das rodas      |
| Fonte de alimentação (pilhas ou bateria) | 1          | Alimenta os motores    |
| Jumpers                                  | Vários     | Conexões elétricas     |
| Chassi do carrinho                       | 1          | Fonte de PC            |

---

## 🪛 Ligações (Pinos)

| ESP8266 | Ponte H | Função              |
| ------- | ------- | ------------------- |
| D1      | IN1     | Motor A - Sentido 1 |
| D2      | IN2     | Motor A - Sentido 2 |
| D3      | IN3     | Motor B - Sentido 1 |
| D4      | IN4     | Motor B - Sentido 2 |

> ⚠️ Verifique a alimentação da ponte H (5V ou 12V conforme o motor utilizado).

---

## 💻 Código

O código configura o ESP8266 como servidor web e define rotas simples (`/F`, `/B`, `/L`, `/R`, `/S`) que acionam os motores conforme o comando recebido.

Exemplo:

```cpp
if (request.indexOf("/F") != -1) forward();
else if (request.indexOf("/B") != -1) backward();
else if (request.indexOf("/L") != -1) left();
else if (request.indexOf("/R") != -1) right();
else if (request.indexOf("/S") != -1) stopMotors();
```

Essas funções ligam e desligam os pinos conforme o movimento desejado.

---

## 📸 Imagens do Projeto

![1000086791](https://github.com/user-attachments/assets/ea01854c-3b02-4bc5-b6d2-f63b2c671b41)

![1000086789](https://github.com/user-attachments/assets/0bab3715-c921-45de-b7c5-0ec8d8102294)

![1000086790](https://github.com/user-attachments/assets/b54b6638-b668-4c85-a82d-35095fdf49c2)

![1000086788](https://github.com/user-attachments/assets/3d2ec0c3-6c0d-4c65-b6e6-b6c5aae12e80)

---

## 🌐 Interface Web

Ao acessar o endereço do ESP8266, é exibida uma página com os botões de controle:

```
Carrinho ESP8266
[Frente]
[Ré]
[Esquerda]
[Direita]
[Parar]
```

Cada botão envia uma requisição HTTP simples ao ESP, que ativa o movimento correspondente.

---

## 🚀 Como usar

1. **Carregue o código** no ESP8266 usando a Arduino IDE.

   * Selecione a placa: `NodeMCU 1.0 (ESP-12E Module)`
   * Verifique a porta correta (COM).
   * Instale a biblioteca `ESP8266WiFi` (já vem por padrão).
2. **Alimente o circuito** (ESP + ponte H + motores).
3. **Conecte-se à rede Wi-Fi**:

   * Nome: `CarrinhoESP`
   * Senha: `12345678`
4. **Abra o navegador** e acesse:
   👉 `http://192.168.4.1`
5. **Use os botões** para controlar o carrinho.

---

## 🧩 Possíveis melhorias

* Adicionar controle por **joystick virtual** (HTML + JavaScript)
* Implementar **velocidade PWM**
* Adicionar **sensor ultrassônico** para desvio de obstáculos
* Controlar via **aplicativo mobile (Blynk, MIT App Inventor, etc.)**

---

## 🧠 Autor

**Gustavo Marcos Xavier**

**Marcelo Berguer Gil**

**Lucas Vinicius**

📅 Projeto desenvolvido com ESP8266 e C++ (Arduino IDE).

💬 Foco em aprendizado e controle de robótica com Wi-Fi.

---

Deseja que eu formate esse README para salvar diretamente como arquivo `.md` (Markdown) pronto para GitHub?
