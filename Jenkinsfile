pipeline {
    agent {
		dockerContainer { image 'gcc:12.4.0'}
	}

    stages {
        stage('Build') {
            steps {
                echo 'RUN make' && make
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
