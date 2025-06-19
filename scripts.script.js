// scripts.script.js

const choices = ['pedra', 'papel', 'tesoura'];
let playerScore = 0;

const buttons = document.querySelectorAll('#choices button');
const resultDiv = document.getElementById('game-result');
const scoreSpan = document.getElementById('player-score');
const resetBtn = document.getElementById('reset-game');

function getMachineChoice() {
    const randomIndex = Math.floor(Math.random() * choices.length);
    return choices[randomIndex];
}

function determineWinner(player, machine) {
    if (player === machine) {
        return 'empate';
    } 
    if (
        (player === 'pedra' && machine === 'tesoura') ||
        (player === 'papel' && machine === 'pedra') ||
        (player === 'tesoura' && machine === 'papel')
    ) {
        return 'vencedor';
    } else {
        return 'perdedor';
    }
}

function updateScore(result) {
    if (result === 'vencedor') {
        playerScore++;
    } else if (result === 'perdedor') {
        playerScore--;
    }
    scoreSpan.textContent = playerScore;
}

function showResult(playerChoice, machineChoice, result) {
    let message = `Você escolheu <strong>${playerChoice}</strong>. Máquina escolheu <strong>${machineChoice}</strong>.<br>`;

    if (result === 'empate') {
        message += "<span style='color: orange;'>Empate!</span>";
    } else if (result === 'vencedor') {
        message += "<span style='color: green;'>Você venceu!</span>";
    } else {
        message += "<span style='color: red;'>Máquina venceu!</span>";
    }
    resultDiv.innerHTML = message;
}

function handleChoiceClick(e) {
  const playerChoice = e.target.getAttribute('data-choice');
  const machineChoice = getMachineChoice();
  const result = determineWinner(playerChoice, machineChoice);
  updateScore(result);
  showResult(playerChoice, machineChoice, result);
  resetBtn.style.display = 'inline-block';

  if (result === 'vencedor') {
    // Pega a posição do clique para animar as coroas
    const x = e.clientX;
    const y = e.clientY;
    criarCoroa(x, y);
  }
}

buttons.forEach(btn => {
    btn.addEventListener('click', handleChoiceClick);
});

resetBtn.addEventListener('click', () => {
    playerScore = 0;
    scoreSpan.textContent = playerScore;
    resultDiv.textContent = '';
    resetBtn.style.display = 'none';
});


function criarCoroa(x, y) {
  const coracoesCount = 30; // pode aumentar pra 50 se quiser mais ainda

  for (let i = 0; i < coracoesCount; i++) {
    const coracao = document.createElement('div');
    coracao.classList.add('coroa-voando');
    coracao.textContent = '❤️';

    // posição aleatória em uma área MAIOR ao redor do clique
    const offsetX = Math.random() * 400 - 200; // -200 a +200 px (largura maior)
    const offsetY = Math.random() * 200 - 100; // -100 a +100 px (altura mais espalhada)

    coracao.style.left = `${x + offsetX}px`;
    coracao.style.top = `${y + offsetY}px`;

    // aleatoriedade no tamanho e rotação
    const tamanho = 20 + Math.random() * 20;
    const rotacao = Math.random() * 360;

    coracao.style.fontSize = `${tamanho}px`;
    coracao.style.transform = `rotate(${rotacao}deg)`;

    document.body.appendChild(coracao);

    coracao.addEventListener('animationend', () => {
      coracao.remove();
    });
  }
}
