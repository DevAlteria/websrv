pipeline {
    agent { dockerfile true }
    stages {
        stage('Build') {
            steps {
                echo 'RUN make'
            }
        }
        stage('Test') {
            steps {
                echo 'TODO: RUN make test all'
            }
        }
        stage('Deploy') {
            steps {
                echo 'TODO: make push request to release branch'
            }
        }
    }
}
